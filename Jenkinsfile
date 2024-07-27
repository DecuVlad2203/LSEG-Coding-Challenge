pipeline{
	agent any
	stages{
		stage('Build') {
			steps {
				sh 'echo "Building..."'
				sh 'chmod +x scripts/Windows-Build.ps1'
				sh 'scripts/Windows-Build.ps1'
				archiveArtifacts artifacts: 'bin/Debug/*', fingerprint: true
			     }
		}
		stage('Run'){
			steps{
				sh 'echo "Running..."'
				sh 'chmod +x scripts/Windows-Run.ps1'
				sh 'scripts/Windows-Run.ps1'		
			}	
		}	
	}
}
