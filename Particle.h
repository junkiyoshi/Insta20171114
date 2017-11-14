#pragma once
#include "ofMain.h"

class Particle
{
public:
	Particle();
	~Particle() {};

	void apply_force(ofVec2f force);
	void update();
	void draw(vector<shared_ptr<Particle>> particles);

	ofVec2f get_location();
private:
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	ofColor body_color;
};