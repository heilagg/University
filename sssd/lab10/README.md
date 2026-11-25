# Lab 10 - CI pipeline & secret management demo

A tiny Flask service with one protected endpoint. The API key is a secret that
is loaded from outside the code (environment variable or a file), never hardcoded.

## Run locally
    python3 -m venv venv && source venv/bin/activate
    pip install -r requirements.txt
    export APP_API_KEY="my-dev-key"
    python3 app.py

## Where the secret comes from
- APP_API_KEY environment variable, or
- a file at secrets/api_key (path overridable via APP_API_KEY_FILE).
