pipeline{
	agent any
	stages{
		stage('Build') {
			steps {
				sh 'echo "Building..."'
				sh 'chmod +x scripts/Linus-Build.sh'
				sh 'scripts/Linux-Build.sh'
				archiveArtifacts artifacts: 'bin/Debug/*', fingerprint: true
			     }
		}
		stage('Run'){
			steps{
				sh 'echo "Running..."'
				sh 'chmod +x scripts/Linus-Run.sh'
				sh 'scripts/Linux-Run.sh'		
			}	
		}	
	}
}
