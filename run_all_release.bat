for /r "Release" %%a in (*.exe) do (
  echo "%%~fa"
  call "%%~fa"
)
