"""
Airflow DAG Template for ML Training Pipelines
This template provides a standard structure for ML training workflows
"""

from datetime import datetime, timedelta
from airflow import DAG
from airflow.providers.cncf.kubernetes.operators.kubernetes_pod import KubernetesPodOperator
from airflow.providers.mlflow.operators.mlflow import MLflowOperator
from airflow.operators.python import PythonOperator
from airflow.utils.dates import days_ago

default_args = {
    'owner': 'data-science',
    'depends_on_past': False,
    'email_on_failure': True,
    'email_on_retry': False,
    'retries': 1,
    'retry_delay': timedelta(minutes=5),
}

dag = DAG(
    'ml_training_pipeline',
    default_args=default_args,
    description='ML Training Pipeline Template',
    schedule_interval=timedelta(days=1),
    start_date=days_ago(1),
    catchup=False,
    tags=['ml', 'training'],
)

# Data preparation task
prepare_data = KubernetesPodOperator(
    task_id='prepare_data',
    name='prepare-data',
    namespace='dev-platform',
    image='python:3.9',
    cmds=['python', '-c'],
    arguments=['print("Preparing data...")'],
    get_logs=True,
    dag=dag,
)

# Feature engineering task
feature_engineering = KubernetesPodOperator(
    task_id='feature_engineering',
    name='feature-engineering',
    namespace='dev-platform',
    image='python:3.9',
    cmds=['python', '-c'],
    arguments=['print("Engineering features...")'],
    get_logs=True,
    dag=dag,
)

# Model training task
train_model = KubernetesPodOperator(
    task_id='train_model',
    name='train-model',
    namespace='dev-platform',
    image='python:3.9',
    cmds=['python', '-c'],
    arguments=['print("Training model...")'],
    env_vars={
        'MLFLOW_TRACKING_URI': 'http://mlflow.dev-platform.svc.cluster.local:5000',
    },
    get_logs=True,
    dag=dag,
)

# Model evaluation task
evaluate_model = KubernetesPodOperator(
    task_id='evaluate_model',
    name='evaluate-model',
    namespace='dev-platform',
    image='python:3.9',
    cmds=['python', '-c'],
    arguments=['print("Evaluating model...")'],
    env_vars={
        'MLFLOW_TRACKING_URI': 'http://mlflow.dev-platform.svc.cluster.local:5000',
    },
    get_logs=True,
    dag=dag,
)

# Model registration in MLflow
register_model = PythonOperator(
    task_id='register_model',
    python_callable=lambda: print("Registering model in MLflow..."),
    dag=dag,
)

# Define task dependencies
prepare_data >> feature_engineering >> train_model >> evaluate_model >> register_model

