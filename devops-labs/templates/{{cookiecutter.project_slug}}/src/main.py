"""
Main entry point for {{ cookiecutter.project_name }}
"""

import mlflow
import os

def main():
    """Main function"""
    # Configure MLflow
    mlflow.set_tracking_uri(os.getenv('MLFLOW_TRACKING_URI', '{{ cookiecutter.mlflow_tracking_uri }}'))
    mlflow.set_experiment("{{ cookiecutter.project_slug }}")
    
    print("{{ cookiecutter.project_name }} - Starting...")
    
    with mlflow.start_run():
        mlflow.log_param("project", "{{ cookiecutter.project_slug }}")
        print("Experiment tracked in MLflow")
    
    print("Done!")

if __name__ == "__main__":
    main()

