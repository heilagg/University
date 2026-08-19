# User Guide

## Getting Started

### Accessing Services

All services are accessible via ingress at:
- **Jupyter**: http://jupyter.platform.local
- **MLflow**: http://mlflow.platform.local
- **Airflow**: http://airflow.platform.local
- **GitLab**: http://gitlab.platform.local
- **Grafana**: http://grafana.platform.local
- **Keycloak**: http://keycloak.platform.local

### First Time Setup

1. **Access Keycloak** and create your account
2. **Login to GitLab** and set up SSH keys
3. **Access Jupyter** and start developing

## Creating a New Project

### Using Cookiecutter Template

```bash
# From Jupyter terminal or local machine
cookiecutter /shared-storage/templates

# Or use the helper script
./scripts/create-project.sh my-new-project
```

The template will create:
- Project structure with `src/`, `tests/`, `notebooks/`
- Pre-configured `.gitlab-ci.yml`
- Dockerfile
- DVC configuration
- MLflow integration

### Manual Project Setup

1. Create GitLab repository
2. Clone repository
3. Initialize DVC:
   ```bash
   dvc init
   dvc remote add -d s3 s3://dvc-storage
   ```
4. Configure MLflow:
   ```bash
   export MLFLOW_TRACKING_URI=http://mlflow.dev-platform.svc.cluster.local:5000
   ```

## Development Workflow

### 1. Data Management with DVC

```bash
# Add data files
dvc add data/raw/dataset.csv

# Push to remote storage
dvc push

# Pull data in another environment
dvc pull
```

### 2. Experiment Tracking with MLflow

```python
import mlflow

mlflow.set_tracking_uri("http://mlflow.dev-platform.svc.cluster.local:5000")
mlflow.set_experiment("my-experiment")

with mlflow.start_run():
    # Your training code
    mlflow.log_param("learning_rate", 0.01)
    mlflow.log_metric("accuracy", 0.95)
    mlflow.log_artifact("model.pkl")
```

### 3. CI/CD Pipeline

The GitLab CI pipeline automatically:
- Builds Docker images
- Runs tests
- Packages MLflow models
- Deploys to environments

Trigger by pushing to `main` or `develop` branches.

### 4. Training with Airflow

Create DAGs in `dags/` directory:

```python
from airflow import DAG
from airflow.providers.cncf.kubernetes.operators.kubernetes_pod import KubernetesPodOperator

dag = DAG('train_model', ...)

train_task = KubernetesPodOperator(
    task_id='train',
    image='my-model:latest',
    ...
)
```

## Monitoring and Observability

### Viewing Metrics

Access Grafana at http://grafana.platform.local
- Default login: admin/admin
- Pre-configured dashboards for:
  - Platform overview
  - Service metrics
  - Kubernetes cluster metrics

### Viewing Logs

Access Loki via Grafana:
1. Go to Grafana → Explore
2. Select Loki as data source
3. Query logs: `{app="jupyter"}`

### Viewing Traces

Access Jaeger at http://jaeger.platform.local
- View distributed traces
- Analyze request flows
- Identify performance bottlenecks

## Secrets Management

### Using Vault

```bash
# Access Vault
export VAULT_ADDR=http://vault.dev-platform.svc.cluster.local:8200
vault login root

# Store secret
vault kv put secret/myapp/database password=secret123

# Retrieve secret
vault kv get secret/myapp/database
```

### Using Kubernetes Secrets

```bash
# Create secret
kubectl create secret generic my-secret \
  --from-literal=username=admin \
  --from-literal=password=secret

# Use in deployment
# Reference in deployment.yaml:
# env:
# - name: PASSWORD
#   valueFrom:
#     secretKeyRef:
#       name: my-secret
#       key: password
```

## Troubleshooting

### Jupyter Not Starting

```bash
# Check pod status
kubectl get pods -n dev-platform -l app=jupyter

# Check logs
kubectl logs -n dev-platform deployment/jupyter

# Check events
kubectl describe pod -n dev-platform -l app=jupyter
```

### MLflow Connection Issues

```bash
# Verify MLflow service
kubectl get svc mlflow -n dev-platform

# Test connectivity
kubectl run -it --rm debug --image=curlimages/curl --restart=Never -- \
  curl http://mlflow.dev-platform.svc.cluster.local:5000
```

### Airflow DAG Not Appearing

1. Check DAG file syntax
2. Verify DAG is in correct directory
3. Check Airflow logs:
   ```bash
   kubectl logs -n dev-platform deployment/airflow-scheduler
   ```

### Storage Issues

```bash
# Check PVC status
kubectl get pvc -n dev-platform

# Check storage class
kubectl get storageclass

# Verify storage provider
kubectl get pods -n storage
```

## Best Practices

### Project Structure

```
project/
├── src/              # Source code
│   ├── data/         # Data processing
│   ├── models/       # Model definitions
│   └── utils/        # Utilities
├── tests/            # Tests
├── notebooks/        # Jupyter notebooks
├── dags/             # Airflow DAGs
├── data/             # Data (DVC managed)
├── models/           # Trained models (MLflow)
└── requirements.txt  # Dependencies
```

### Version Control

- Use Git for code
- Use DVC for data
- Use MLflow for models
- Tag releases in GitLab

### CI/CD

- Keep pipelines fast (< 10 minutes)
- Use caching for dependencies
- Run tests before deployment
- Use feature branches

### Monitoring

- Add custom metrics to applications
- Set up alerts for critical issues
- Review logs regularly
- Monitor resource usage

## Support

For issues or questions:
1. Check documentation in `docs/`
2. Review logs and metrics
3. Contact platform administrators
4. Create issue in GitLab

