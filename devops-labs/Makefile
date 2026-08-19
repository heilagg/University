.PHONY: help deploy destroy status logs clean

help: ## Show this help message
	@echo 'Usage: make [target]'
	@echo ''
	@echo 'Available targets:'
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "  %-15s %s\n", $$1, $$2}' $(MAKEFILE_LIST)

deploy: ## Deploy the entire platform
	@./scripts/deploy.sh

deploy-storage: ## Deploy storage layer only
	@./scripts/setup-storage.sh

setup-keycloak: ## Setup Keycloak configuration
	@./scripts/setup-keycloak.sh

status: ## Show status of all deployments
	@echo "=== Dev Platform ==="
	@kubectl get pods -n dev-platform
	@echo ""
	@echo "=== Monitoring ==="
	@kubectl get pods -n monitoring
	@echo ""
	@echo "=== CI/CD ==="
	@kubectl get pods -n ci-cd
	@echo ""
	@echo "=== Storage ==="
	@kubectl get pods -n storage

logs-jupyter: ## Show Jupyter logs
	@kubectl logs -f deployment/jupyter -n dev-platform

logs-mlflow: ## Show MLflow logs
	@kubectl logs -f deployment/mlflow -n dev-platform

logs-airflow: ## Show Airflow logs
	@kubectl logs -f deployment/airflow-webserver -n dev-platform

logs-gitlab: ## Show GitLab logs
	@kubectl logs -f deployment/gitlab -n ci-cd

logs-prometheus: ## Show Prometheus logs
	@kubectl logs -f deployment/prometheus -n monitoring

logs-grafana: ## Show Grafana logs
	@kubectl logs -f deployment/grafana -n monitoring

port-forward-jupyter: ## Port forward Jupyter
	@kubectl port-forward svc/jupyter 8888:8888 -n dev-platform

port-forward-mlflow: ## Port forward MLflow
	@kubectl port-forward svc/mlflow 5000:5000 -n dev-platform

port-forward-airflow: ## Port forward Airflow
	@kubectl port-forward svc/airflow-webserver 8080:8080 -n dev-platform

port-forward-grafana: ## Port forward Grafana
	@kubectl port-forward svc/grafana 3000:3000 -n monitoring

port-forward-keycloak: ## Port forward Keycloak
	@kubectl port-forward svc/keycloak 8080:8080 -n dev-platform

clean: ## Clean up all resources (WARNING: destructive)
	@echo "WARNING: This will delete all platform resources!"
	@read -p "Are you sure? [y/N] " -n 1 -r; \
	echo; \
	if [[ $$REPLY =~ ^[Yy]$$ ]]; then \
		kubectl delete namespace dev-platform monitoring storage ci-cd || true; \
		echo "Cleanup completed"; \
	fi

create-project: ## Create a new project from template
	@read -p "Project name: " name; \
	./scripts/create-project.sh "$$name"

