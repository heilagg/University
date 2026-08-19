"""
Model training script
"""

import mlflow
import os
import json

def train_model():
    """Train the model"""
    print("Training model...")
    
    # Configure MLflow
    mlflow.set_tracking_uri(os.getenv('MLFLOW_TRACKING_URI', '{{ cookiecutter.mlflow_tracking_uri }}'))
    mlflow.set_experiment("{{ cookiecutter.project_slug }}")
    
    with mlflow.start_run():
        # Your training logic here
        # model = train(...)
        # accuracy = evaluate(model, test_data)
        
        # Log parameters
        mlflow.log_param("model_type", "baseline")
        
        # Log metrics
        accuracy = 0.95  # Replace with actual metric
        mlflow.log_metric("accuracy", accuracy)
        
        # Save metrics for DVC
        os.makedirs("metrics", exist_ok=True)
        with open("metrics/accuracy.json", "w") as f:
            json.dump({"accuracy": accuracy}, f)
        
        # Log model
        # mlflow.sklearn.log_model(model, "model")
        
        print(f"Model trained with accuracy: {accuracy}")

if __name__ == "__main__":
    train_model()

