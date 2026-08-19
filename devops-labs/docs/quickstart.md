# Quick Start Guide

Get the platform up and running in 5 minutes.

## Prerequisites Check

```bash
# Verify Kubernetes access
kubectl cluster-info

# Check Helm
helm version

# Verify storage class exists
kubectl get storageclass
```

## One-Command Deployment

```bash
# Deploy everything
make deploy

# Or use the script directly
./scripts/deploy.sh
```

## Verify Deployment

```bash
# Check all pods are running
make status

# Or manually
kubectl get pods --all-namespaces
```

## Access Services

### Port Forwarding (if ingress not configured)

```bash
# Jupyter
make port-forward-jupyter
# Access at http://localhost:8888

# MLflow
make port-forward-mlflow
# Access at http://localhost:5000

# Airflow
make port-forward-airflow
# Access at http://localhost:8080

# Grafana
make port-forward-grafana
# Access at http://localhost:3000 (admin/admin)

# Keycloak
make port-forward-keycloak
# Access at http://localhost:8080 (admin/admin)
```

## First Steps

1. **Configure Keycloak**
   ```bash
   make setup-keycloak
   # Then access http://localhost:8080 and create realm
   ```

2. **Create Your First Project**
   ```bash
   make create-project
   # Enter project name when prompted
   ```

3. **Start Developing**
   - Access Jupyter at http://localhost:8888
   - Create notebooks in your project
   - Track experiments with MLflow

## Common Commands

```bash
# View logs
make logs-jupyter
make logs-mlflow
make logs-airflow

# Check status
make status

# Create new project
make create-project

# Clean up (WARNING: deletes everything)
make clean
```

## Troubleshooting

### Pods not starting

```bash
# Check pod events
kubectl describe pod <pod-name> -n <namespace>

# Check logs
kubectl logs <pod-name> -n <namespace>
```

### Storage issues

```bash
# Check PVCs
kubectl get pvc --all-namespaces

# Check storage class
kubectl get storageclass
```

### Network issues

```bash
# Test connectivity
kubectl run -it --rm debug --image=busybox --restart=Never -- sh
# Then try: wget -O- http://mlflow.dev-platform.svc.cluster.local:5000
```

## Next Steps

- Read the [User Guide](user-guide.md) for detailed usage
- Check [Architecture](architecture.md) for system design
- Review [API Documentation](api.md) for integrations

