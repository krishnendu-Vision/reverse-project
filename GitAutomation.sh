#!/bin/bash
set -e

cd /data/data/com.termux/files/home/reverse-project
echo "[+]Pulling origin main and rebasing!"

# Catch ANY error during git pull
if ! git pull --rebase origin main; then
    STATUS_CODE=$?
    echo "[-] Git pull failed with exit code $STATUS_CODE"

    # Check if the error is because you forgot to commit local changes (Error 128 / 1)
    if git status --porcelain | grep -q '^[M? ]'; then
        echo "[+] Local changes detected. Staging, committing, and pushing..."
        git add .
        git commit -m 'Updating files!'
        git push origin main
    else
        # If it's a network issue or a real merge conflict, stop here safely
        echo "[-] Error is not due to uncommitted files. Manual intervention required."
        exit $STATUS_CODE
    fi
fi
