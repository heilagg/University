FROM python:{{ cookiecutter.python_version }}-slim

WORKDIR /app

COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

COPY src/ ./src/
COPY models/ ./models/

ENV PYTHONPATH=/app
ENV MLFLOW_TRACKING_URI={{ cookiecutter.mlflow_tracking_uri }}

CMD ["python", "src/main.py"]

