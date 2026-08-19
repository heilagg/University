#!/bin/bash

set -e

echo "🔐 Setting up Keycloak..."

KEYCLOAK_URL="${KEYCLOAK_URL:-http://keycloak.platform.local}"
ADMIN_USER="${KEYCLOAK_ADMIN:-admin}"
ADMIN_PASS="${KEYCLOAK_ADMIN_PASSWORD:-admin}"

echo "Waiting for Keycloak to be ready..."
kubectl wait --for=condition=ready pod -l app=keycloak -n dev-platform --timeout=300s

echo "Keycloak is ready. Please configure:"
echo "1. Access Keycloak admin console: $KEYCLOAK_URL"
echo "2. Login with: $ADMIN_USER / $ADMIN_PASS"
echo "3. Create realm: 'dev-platform'"
echo "4. Create clients for: Jupyter, Airflow, MLflow, GitLab"
echo "5. Configure roles and users"

# You can automate this with Keycloak REST API or Terraform provider
echo ""
echo "For automated setup, use the Keycloak Terraform provider or REST API"
echo "See: terraform/keycloak/ for configuration examples"

