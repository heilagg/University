#!/bin/bash

set -e

echo "🚀 Deploying Unified Development Platform..."

# Check prerequisites
command -v kubectl >/dev/null 2>&1 || { echo "kubectl is required but not installed. Aborting." >&2; exit 1; }
command -v helm >/dev/null 2>&1 || { echo "helm is required but not installed. Aborting." >&2; exit 1; }

# Create namespaces
echo "📦 Creating namespaces..."
kubectl create namespace dev-platform --dry-run=client -o yaml | kubectl apply -f -
kubectl create namespace monitoring --dry-run=client -o yaml | kubectl apply -f -
kubectl create namespace storage --dry-run=client -o yaml | kubectl apply -f -
kubectl create namespace ci-cd --dry-run=client -o yaml | kubectl apply -f -

# Deploy storage layer
echo "💾 Deploying storage layer..."
kubectl apply -f kubernetes/storage/

# Deploy monitoring stack
echo "📊 Deploying monitoring stack..."
kubectl apply -f kubernetes/monitoring/

# Deploy Keycloak for authentication
echo "🔐 Deploying Keycloak..."
kubectl apply -f kubernetes/auth/keycloak/

# Deploy CI/CD components
echo "🔄 Deploying CI/CD components..."
kubectl apply -f kubernetes/ci-cd/

# Deploy dev environment
echo "💻 Deploying dev environment..."
kubectl apply -f kubernetes/dev-env/

# Deploy training/running environment
echo "🏃 Deploying training/running environment..."
kubectl apply -f kubernetes/training/

# Wait for deployments
echo "⏳ Waiting for deployments to be ready..."
kubectl wait --for=condition=available --timeout=300s deployment --all -n dev-platform || true
kubectl wait --for=condition=available --timeout=300s deployment --all -n monitoring || true

echo "✅ Platform deployment completed!"
echo ""
echo "Access the services:"
echo "  - Jupyter: http://jupyter.platform.local"
echo "  - MLflow: http://mlflow.platform.local"
echo "  - Airflow: http://airflow.platform.local"
echo "  - GitLab: http://gitlab.platform.local"
echo "  - Grafana: http://grafana.platform.local"
echo "  - Keycloak: http://keycloak.platform.local"

