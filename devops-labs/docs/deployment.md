# Deployment Guide

## Prerequisites

- Kubernetes cluster (1.20+)
- kubectl configured and connected to cluster
- Helm 3.x installed
- Storage provisioner (for persistent volumes)
- Ingress controller (NGINX recommended)

## Step 1: Prepare Cluster

```bash
# Verify cluster access
kubectl cluster-info

# Create namespaces
kubectl create namespace dev-platform
kubectl create namespace monitoring
kubectl create namespace storage
kubectl create namespace ci-cd
```

## Step 2: Deploy Storage Layer

Choose either GlusterFS or Ceph:

### Option A: GlusterFS

```bash
# Deploy GlusterFS
kubectl apply -f kubernetes/storage/glusterfs/

# Wait for GlusterFS to be ready
kubectl wait --for=condition=ready pod -l app=glusterfs -n storage --timeout=300s

# Create storage class
kubectl apply -f kubernetes/storage/glusterfs/storageclass.yaml
```

### Option B: Ceph

```bash
# Deploy Ceph (requires additional setup)
kubectl apply -f kubernetes/storage/ceph/
```

## Step 3: Deploy Monitoring Stack

```bash
# Deploy Prometheus
kubectl apply -f kubernetes/monitoring/prometheus/

# Deploy Grafana
kubectl apply -f kubernetes/monitoring/grafana/

# Deploy Loki
kubectl apply -f kubernetes/monitoring/loki/

# Deploy Jaeger
kubectl apply -f kubernetes/monitoring/jaeger/

# Deploy AlertManager
kubectl apply -f kubernetes/monitoring/alertmanager/
```

## Step 4: Deploy Authentication

```bash
# Deploy Keycloak
kubectl apply -f kubernetes/auth/keycloak/

# Wait for Keycloak to be ready
kubectl wait --for=condition=ready pod -l app=keycloak -n dev-platform --timeout=300s

# Configure Keycloak (see setup-keycloak.sh)
./scripts/setup-keycloak.sh
```

## Step 5: Deploy CI/CD Components

```bash
# Deploy GitLab
kubectl apply -f kubernetes/ci-cd/gitlab/

# Deploy Nexus
kubectl apply -f kubernetes/ci-cd/nexus/
```

## Step 6: Deploy Development Environment

```bash
# Deploy Jupyter
kubectl apply -f kubernetes/dev-env/jupyter/

# Deploy MLflow
kubectl apply -f kubernetes/dev-env/mlflow/
```

## Step 7: Deploy Training Environment

```bash
# Deploy Airflow
kubectl apply -f kubernetes/training/airflow/

# Initialize Airflow database
kubectl exec -it deployment/airflow-webserver -n dev-platform -- airflow db init
```

## Step 8: Deploy Secrets Management

```bash
# Deploy Vault
kubectl apply -f kubernetes/secrets/vault/
```

## Step 9: Configure Ingress

```bash
# Deploy ingress controller (if not already installed)
kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/main/deploy/static/provider/cloud/deploy.yaml

# Deploy platform ingress
kubectl apply -f kubernetes/ingress/ingress.yaml
```

## Step 10: Apply Network Policies

```bash
# Deploy network policies
kubectl apply -f kubernetes/network-policies/
```

## Step 11: Verify Deployment

```bash
# Check all pods are running
kubectl get pods --all-namespaces

# Check services
kubectl get svc --all-namespaces

# Check ingress
kubectl get ingress --all-namespaces
```

## Post-Deployment Configuration

### 1. Configure Keycloak

1. Access Keycloak admin console: http://keycloak.platform.local
2. Login with admin/admin
3. Create realm: `dev-platform`
4. Create clients for each service:
   - Jupyter
   - Airflow
   - MLflow
   - GitLab
   - Grafana
5. Configure roles and users

### 2. Configure MinIO

1. Access MinIO console: http://minio.dev-platform.svc.cluster.local:9001
2. Login with minioadmin/minioadmin
3. Create buckets:
   - mlflow-artifacts
   - dvc-storage
   - airflow-logs

### 3. Configure GitLab

1. Access GitLab: http://gitlab.platform.local
2. Set root password on first login
3. Create access token for CI/CD
4. Configure runners (if needed)

### 4. Configure Nexus

1. Access Nexus: http://nexus.ci-cd.svc.cluster.local:8081
2. Login with admin/admin123
3. Create repositories for Docker and Maven
4. Configure access

## Troubleshooting

### Pods not starting

```bash
# Check pod status
kubectl describe pod <pod-name> -n <namespace>

# Check logs
kubectl logs <pod-name> -n <namespace>
```

### Storage issues

```bash
# Check PVC status
kubectl get pvc --all-namespaces

# Check storage class
kubectl get storageclass
```

### Network issues

```bash
# Check network policies
kubectl get networkpolicies --all-namespaces

# Test connectivity
kubectl run -it --rm debug --image=busybox --restart=Never -- sh
```

## Upgrading

```bash
# Update deployments
kubectl set image deployment/<deployment-name> <container-name>=<new-image> -n <namespace>

# Rollback if needed
kubectl rollout undo deployment/<deployment-name> -n <namespace>
```

## Backup and Recovery

### Backup

```bash
# Backup databases
kubectl exec -it <db-pod> -n <namespace> -- pg_dump -U <user> <database> > backup.sql

# Backup persistent volumes (requires volume snapshot support)
```

### Recovery

```bash
# Restore database
kubectl exec -i <db-pod> -n <namespace> -- psql -U <user> <database> < backup.sql
```

