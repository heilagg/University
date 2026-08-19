# Unified Development Platform

A comprehensive self-service platform for CI/CD pipelines, automated environment provisioning, and service templates with centralized observability, monitoring, and secure access management.

## Architecture Overview

The platform consists of three main components:

### 1. Dev Environment
- **Jupyter Hub**: Interactive development environment
- **MLflow**: Model tracking and experiment management
- **DVC**: Data version control
- **Cookiecutter**: Project template generation for GitLab/GitHub
- **Persistent Storage**: GlusterFS/Ceph for shared volumes

### 2. CI/CD Infrastructure
- **GitLab**: Source code management and CI/CD pipelines
- **Nexus**: Artifact repository
- **Keycloak**: Centralized authentication and authorization
- **Grafana**: Monitoring dashboards

### 3. Running/Training Environment
- **Airflow**: Workflow orchestration
- **MLflow**: Model registry and deployment tracking

## Observability Stack

- **Prometheus**: Metrics collection
- **Grafana**: Visualization and dashboards
- **Loki**: Log aggregation
- **Jaeger**: Distributed tracing
- **AlertManager**: Automated alerting

## Security Features

- **Keycloak**: Single Sign-On (SSO) and RBAC
- **Vault**: Secrets management
- **Audit Logging**: Comprehensive audit trails
- **Network Policies**: Kubernetes network isolation

## Quick Start

### Prerequisites

- Kubernetes cluster (1.20+)
- kubectl configured
- Helm 3.x
- Storage provisioner (for persistent volumes)

### Installation

```bash
# Deploy infrastructure
./scripts/deploy.sh

# Configure Keycloak
./scripts/setup-keycloak.sh

# Initialize storage
./scripts/setup-storage.sh
```

## Directory Structure

```
.
├── kubernetes/          # Kubernetes manifests
├── docker/              # Dockerfiles for services
├── terraform/           # Infrastructure as Code
├── ansible/             # Configuration management
├── pipelines/           # CI/CD pipeline templates
├── templates/           # Service templates
├── monitoring/          # Observability configurations
├── scripts/             # Deployment and utility scripts
└── docs/                # Documentation
```

## Services

- **Jupyter Hub**: http://jupyter.platform.local
- **MLflow**: http://mlflow.platform.local
- **Airflow**: http://airflow.platform.local
- **GitLab**: http://gitlab.platform.local
- **Grafana**: http://grafana.platform.local
- **Keycloak**: http://keycloak.platform.local

## Documentation

See [docs/](docs/) for detailed documentation on:
- Architecture design
- Deployment guide
- User guide
- API documentation
- Troubleshooting

## License

MIT

