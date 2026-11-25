"""
Lab 10 demo app - a tiny Flask service protected by an API key.

The API key is a SECRET. It is never hardcoded: the app loads it at runtime
from an environment variable, or from a file (external provisioning).
"""
import os
from flask import Flask, request, jsonify

app = Flask(__name__)


def load_secret():
    """Load the API key from outside the code: env var first, then a file."""
    key = os.environ.get("APP_API_KEY")
    if key:
        return key.strip()
    path = os.environ.get("APP_API_KEY_FILE", "secrets/api_key")
    try:
        with open(path) as f:
            return f.read().strip()
    except FileNotFoundError:
        return None


@app.route("/")
def home():
    return "Lab 10 demo app is running. Call /secure with header X-API-Key."


@app.route("/secure")
def secure():
    expected = load_secret()
    if not expected:
        return jsonify(error="server secret is not configured"), 500
    provided = request.headers.get("X-API-Key", "")
    if provided != expected:
        return jsonify(error="forbidden"), 403
    return jsonify(message="access granted - the secret matched")


if __name__ == "__main__":
    app.run(port=5050)
