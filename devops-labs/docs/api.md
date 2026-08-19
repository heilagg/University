# API Documentation

## MLflow API

### Tracking URI
```
http://mlflow.dev-platform.svc.cluster.local:5000
```

### Create Experiment
```python
import mlflow

mlflow.set_tracking_uri("http://mlflow.dev-platform.svc.cluster.local:5000")
experiment_id = mlflow.create_experiment("my-experiment")
```

### Log Run
```python
with mlflow.start_run(experiment_id=experiment_id):
    mlflow.log_param("param1", "value1")
    mlflow.log_metric("metric1", 0.95)
    mlflow.log_artifact("model.pkl")
```

### REST API Endpoints

- `GET /api/2.0/mlflow/experiments/search` - List experiments
- `GET /api/2.0/mlflow/runs/search` - Search runs
- `POST /api/2.0/mlflow/runs/create` - Create run
- `GET /api/2.0/mlflow/artifacts/list` - List artifacts

## GitLab API

### Base URL
```
http://gitlab.platform.local/api/v4
```

### Create Project
```bash
curl -X POST "http://gitlab.platform.local/api/v4/projects" \
  -H "PRIVATE-TOKEN: YOUR_TOKEN" \
  -H "Content-Type: application/json" \
  -d '{"name": "my-project"}'
```

### List Projects
```bash
curl "http://gitlab.platform.local/api/v4/projects" \
  -H "PRIVATE-TOKEN: YOUR_TOKEN"
```

## Nexus API

### Base URL
```
http://nexus.ci-cd.svc.cluster.local:8081/service/rest/v1
```

### Upload Artifact
```bash
curl -X POST "http://nexus.ci-cd.svc.cluster.local:8081/service/rest/v1/components?repository=docker-hosted" \
  -u admin:admin123 \
  -H "Content-Type: multipart/form-data" \
  -F "docker.image=my-image:latest" \
  -F "docker.asset=@image.tar"
```

## Keycloak API

### Base URL
```
http://keycloak.platform.local/auth/realms/dev-platform
```

### Get Token
```bash
curl -X POST "http://keycloak.platform.local/auth/realms/dev-platform/protocol/openid-connect/token" \
  -H "Content-Type: application/x-www-form-urlencoded" \
  -d "grant_type=password&client_id=my-client&username=user&password=pass"
```

## Vault API

### Base URL
```
http://vault.dev-platform.svc.cluster.local:8200/v1
```

### Read Secret
```bash
curl -H "X-Vault-Token: YOUR_TOKEN" \
  http://vault.dev-platform.svc.cluster.local:8200/v1/secret/data/myapp
```

### Write Secret
```bash
curl -X POST -H "X-Vault-Token: YOUR_TOKEN" \
  -H "Content-Type: application/json" \
  -d '{"data": {"password": "secret123"}}' \
  http://vault.dev-platform.svc.cluster.local:8200/v1/secret/data/myapp
```

## Prometheus API

### Base URL
```
http://prometheus.monitoring.svc.cluster.local:9090/api/v1
```

### Query
```bash
curl "http://prometheus.monitoring.svc.cluster.local:9090/api/v1/query?query=up"
```

### Query Range
```bash
curl "http://prometheus.monitoring.svc.cluster.local:9090/api/v1/query_range?query=up&start=2023-01-01T00:00:00Z&end=2023-01-01T23:59:59Z&step=15s"
```

## Airflow API

### Base URL
```
http://airflow.platform.local/api/v1
```

### Trigger DAG
```bash
curl -X POST "http://airflow.platform.local/api/v1/dags/my-dag/dagRuns" \
  -H "Authorization: Basic $(echo -n user:pass | base64)" \
  -H "Content-Type: application/json" \
  -d '{"conf": {}}'
```

### Get DAG Status
```bash
curl "http://airflow.platform.local/api/v1/dags/my-dag" \
  -H "Authorization: Basic $(echo -n user:pass | base64)"
```

