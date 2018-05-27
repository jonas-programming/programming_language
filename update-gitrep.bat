@echo off
git add -A
git status
set /p mess="Commit Message: "
git commit -m "%mess%"
git push origin master