#!/usr/bin/env bash
# Generate a simple files-changed list for the Shadow fork
# Usage: ./dev_scripts/gen_shadow_filelist.sh BASE_BRANCH > docs/SHADOW_FILELIST.md

BASE_BRANCH="${1:-upstream/upcoming}"

echo "# Shadow fork – Files changed vs ${BASE_BRANCH}"
echo
git diff --name-status "${BASE_BRANCH}"...HEAD | sed 's/^/    /'
