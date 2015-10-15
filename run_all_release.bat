for /r "." %%a in (*.exe) do (
  echo "%%~fa"
  start /WAIT /B "%%~fa"
)
