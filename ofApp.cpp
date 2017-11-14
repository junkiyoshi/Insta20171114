#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);

	for (int i = 0; i < 1024; i++) {
		this->particles.push_back(shared_ptr<Particle>(new Particle()));
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (int i = 0; i < this->particles.size(); i++) {
		if (ofGetMousePressed()) {
			ofVec2f mouse_point = ofVec2f(ofGetMouseX(), ofGetMouseY());
			ofVec2f distance = this->particles[i]->get_location() - mouse_point;

			if (distance.length() < 150) {
				this->particles[i]->apply_force(distance.limit(5));
			}
		}
		this->particles[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < this->particles.size(); i++) {
		this->particles[i]->draw(this->particles);
	}
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}