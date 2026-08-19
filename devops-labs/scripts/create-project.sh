#!/bin/bash

set -e

PROJECT_NAME="${1:-}"
GITLAB_URL="${GITLAB_URL:-http://gitlab.platform.local}"
COOKIECUTTER_TEMPLATE="${COOKIECUTTER_TEMPLATE:-/shared-storage/templates}"

if [ -z "$PROJECT_NAME" ]; then
    echo "Usage: $0 <project-name>"
    exit 1
fi

echo "🚀 Creating new project: $PROJECT_NAME"

# Check if cookiecutter is installed
if ! command -v cookiecutter &> /dev/null; then
    echo "Installing cookiecutter..."
    pip install cookiecutter
fi

# Create project from template
echo "📦 Creating project from template..."
cookiecutter $COOKIECUTTER_TEMPLATE --no-input project_name="$PROJECT_NAME"

PROJECT_DIR="${PROJECT_NAME// /-}"
cd "$PROJECT_DIR"

# Initialize git repository
echo "📝 Initializing git repository..."
git init
git add .
git commit -m "Initial commit from template"

# Create GitLab project and push
echo "🔗 Creating GitLab project..."
GITLAB_TOKEN="${GITLAB_TOKEN:-}"
if [ -n "$GITLAB_TOKEN" ]; then
    curl -X POST "$GITLAB_URL/api/v4/projects" \
        -H "PRIVATE-TOKEN: $GITLAB_TOKEN" \
        -H "Content-Type: application/json" \
        -d "{\"name\": \"$PROJECT_NAME\", \"visibility\": \"private\"}"
    
    git remote add origin "$GITLAB_URL/$PROJECT_NAME.git"
    git push -u origin main
else
    echo "⚠️  GITLAB_TOKEN not set. Skipping GitLab project creation."
    echo "   Create project manually and run: git remote add origin <url>"
fi

# Initialize DVC
echo "📊 Initializing DVC..."
dvc init
dvc remote add -d s3 s3://dvc-storage
git add .dvc .gitignore
git commit -m "Initialize DVC"

echo "✅ Project created successfully!"
echo "   Location: $(pwd)"
echo "   Next steps:"
echo "   1. cd $PROJECT_DIR"
echo "   2. Configure MLflow tracking URI"
echo "   3. Start developing!"

