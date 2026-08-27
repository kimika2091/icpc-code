param(
    [int]$Rounds = 10000
)

$ErrorActionPreference = 'Stop'

$workDir = $PSScriptRoot
$runId = [Guid]::NewGuid().ToString('N')
$candidateExe = Join-Path $env:TEMP "M_candidate_$runId.exe"
$bruteExe = Join-Path $env:TEMP "M_brute_$runId.exe"
$generatorExe = Join-Path $env:TEMP "M_gen_$runId.exe"
$counterexample = Join-Path $workDir 'M_counterexample.txt'

try {
    g++ -std=c++17 -O2 (Join-Path $workDir 'M.cpp') -o $candidateExe
    if ($LASTEXITCODE -ne 0) { throw 'M.cpp compile failed' }

    g++ -std=c++17 -O2 (Join-Path $workDir 'M_brute.cpp') -o $bruteExe
    if ($LASTEXITCODE -ne 0) { throw 'M_brute.cpp compile failed' }

    g++ -std=c++17 -O2 (Join-Path $workDir 'M_gen.cpp') -o $generatorExe
    if ($LASTEXITCODE -ne 0) { throw 'M_gen.cpp compile failed' }

    for ($round = 1; $round -le $Rounds; ++$round) {
        $inputData = (& $generatorExe | Out-String)
        $candidateOutput = ($inputData | & $candidateExe | Out-String).Trim()
        $bruteOutput = ($inputData | & $bruteExe | Out-String).Trim()

        if ($candidateOutput -ne $bruteOutput) {
            Set-Content -LiteralPath $counterexample -Value $inputData -NoNewline
            Write-Host "Wrong answer on round $round"
            Write-Host 'Input:'
            Write-Host $inputData
            Write-Host "Candidate: $candidateOutput"
            Write-Host "Brute:     $bruteOutput"
            Write-Host "Saved to: $counterexample"
            exit 1
        }

        if ($round % 100 -eq 0) {
            Write-Host "Accepted $round tests"
        }
    }

    Write-Host "All $Rounds tests passed"
}
finally {
    Remove-Item -LiteralPath $candidateExe, $bruteExe, $generatorExe -Force -ErrorAction SilentlyContinue
}
