pipeline{
	agent any
	stages{
		stage('Build') {
			steps {
				sh 'echo "Building..."'
				sh 'chmod +x scripts/Windows-Build.sh'
				sh 'scripts/Windows-Build.sh'
				archiveArtifacts artifacts: 'bin/Debug/*', fingerprint: true
			     }
		}
		stage('Run'){
			steps{
				sh 'echo "Running..."'
				sh 'chmod +x scripts/Windows-Run.sh'
				sh 'scripts/Windows-Run.sh'		
			}	
		}	
	}
}
