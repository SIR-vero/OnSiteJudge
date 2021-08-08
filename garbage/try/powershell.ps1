$StopWatch = [system.diagnostics.stopwatch]::startNew()
Start-Process .\a -RedirectStandardInput .\in.txt -RedirectStandardOutput .\out.txt -NoNewWindow -Wait
$StopWatch.Stop()
$StopWatch.Elapsed
$Age = Read-Host "Please enter your age"