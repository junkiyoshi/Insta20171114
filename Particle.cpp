#include "Particle.h"

Particle::Particle() {
	this->location = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	this->velocity = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
	this->acceleration = ofVec2f();
	this->body_color.setHsb(ofRandom(255), 255, 255);
	//this->body_color = ofColor(0);
}

void Particle::apply_force(ofVec2f force) {
	this->acceleration += force;
}

void Particle::update() {
	this->acceleration += this->velocity;
	this->location += this->acceleration;
	this->acceleration *= 0;

	if (this->location.x < 0) {
		this->location.x = 0;
		this->velocity.x *= -1;
	}
	else if (this->location.x > ofGetWidth()) {
		this->location.x = ofGetWidth();
		this->velocity.x *= -1;
	}

	if (this->location.y < 0) {
		this->location.y = 0;
		this->velocity.y *= -1;
	}
	else if (this->location.y > ofGetHeight()) {
		this->location.y = ofGetHeight();
		this->velocity.y *= -1;
	}
}

void Particle::draw(vector<shared_ptr<Particle>> particles) {

	ofSetColor(this->body_color);
	ofDrawCircle(this->location, 1);

	float distance;
	for (int i = 0; i < particles.size(); i++) {
		distance = this->location.distance(particles[i]->get_location());
		if (distance > 0 && distance < 64) {
			ofDrawLine(this->location, particles[i]->get_location());
		}
	}
}

ofVec2f Particle::get_location() {
	return this->location;
}