# Lab 10 - centralized secret provisioning (HashiCorp Vault)

The secret lives only in Vault, not in code or git. The app authenticates with a
token and fetches the secret at runtime.

## Run Vault (dev mode)
    docker run -d --name vault-dev -p 8200:8200 \
      -e 'VAULT_DEV_ROOT_TOKEN_ID=root' \
      -e 'VAULT_DEV_LISTEN_ADDRESS=0.0.0.0:8200' hashicorp/vault

## Store the secret
    docker exec -e VAULT_ADDR=http://127.0.0.1:8200 -e VAULT_TOKEN=root vault-dev \
      vault kv put secret/lab10 APP_API_KEY=<YOUR_SECRET_VALUE>

## App fetches it from Vault at runtime
    ./run_with_vault.sh
