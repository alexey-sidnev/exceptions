for /r "." %%a in (*.exe) do (
  echo "%%~fa"
  "%%~fa"
)
