#!/bin/bash

set -e

STORAGE_TYPE="${STORAGE_TYPE:-glusterfs}"

echo "💾 Setting up storage layer: $STORAGE_TYPE"

if [ "$STORAGE_TYPE" = "glusterfs" ]; then
    echo "Deploying GlusterFS..."
    kubectl apply -f kubernetes/storage/glusterfs/
    
    echo "Creating storage classes..."
    kubectl apply -f kubernetes/storage/glusterfs/storageclass.yaml
    
    echo "Waiting for GlusterFS to be ready..."
    kubectl wait --for=condition=ready pod -l app=glusterfs -n storage --timeout=300s
    
elif [ "$STORAGE_TYPE" = "ceph" ]; then
    echo "Deploying Ceph..."
    kubectl apply -f kubernetes/storage/ceph/
    
    echo "Creating storage classes..."
    kubectl apply -f kubernetes/storage/ceph/storageclass.yaml
    
    echo "Waiting for Ceph to be ready..."
    kubectl wait --for=condition=ready pod -l app=ceph -n storage --timeout=300s
else
    echo "Unknown storage type: $STORAGE_TYPE"
    echo "Using default storage class"
fi

echo "✅ Storage setup completed!"

