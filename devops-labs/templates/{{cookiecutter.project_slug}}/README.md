# {{ cookiecutter.project_name }}

{{ cookiecutter.description }}

## Project Structure

```
.
├── src/              # Source code
├── tests/            # Test files
├── data/             # Data files (gitignored, use DVC)
├── models/           # Trained models (gitignored, use MLflow)
├── notebooks/        # Jupyter notebooks
├── dags/             # Airflow DAGs
├── requirements.txt  # Python dependencies
├── Dockerfile        # Docker configuration
├── .gitlab-ci.yml    # CI/CD pipeline
└── dvc.yaml          # DVC pipeline configuration
```

## Setup

1. Install dependencies:
```bash
pip install -r requirements.txt
```

2. Configure MLflow:
```bash
export MLFLOW_TRACKING_URI={{ cookiecutter.mlflow_tracking_uri }}
```

3. Configure DVC:
```bash
dvc remote add -d {{ cookiecutter.dvc_remote }} {{ cookiecutter.dvc_remote_url }}
dvc pull
```

## Development

- Use Jupyter notebooks in `notebooks/` for exploration
- Source code goes in `src/`
- Tests in `tests/`

## CI/CD

This project uses GitLab CI/CD. The pipeline:
- Builds Docker images
- Runs tests
- Packages MLflow models
- Deploys to environments

## Training

Use Airflow DAGs in `dags/` to orchestrate training pipelines.

## Model Tracking

Models are tracked in MLflow at {{ cookiecutter.mlflow_tracking_uri }}

