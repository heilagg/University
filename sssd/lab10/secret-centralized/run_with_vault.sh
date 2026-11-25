#!/usr/bin/env bash
# Lab 10 - centralized secret provisioning.
# Fetch APP_API_KEY from Vault at runtime, then start the app with it.
set -e
export APP_API_KEY="$(docker exec \
  -e VAULT_ADDR=http://127.0.0.1:8200 -e VAULT_TOKEN=root vault-dev \
  vault kv get -field=APP_API_KEY secret/lab10)"
echo "Fetched APP_API_KEY from Vault (centralized store)."
cd "$HOME/University/sssd/lab10"
source venv/bin/activate
python3 app.py
