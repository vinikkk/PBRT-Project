#pragma once

#include <vector>

using namespace std;

class Scene
{
public:
	Scene() {
		bound = aggregate->WorldBound();
		if (volumeRegion) bound = Union(bound, volumeRegion->WorldBound());
	};
	~Scene();

	//FUNCTIONS
	bool Intersect(const Ray &ray, Intersection *isect) const {
		bool hit = aggregate->Intersect(ray, insect);
		return hit;
	};

	bool IntersectP(const Ray &ray) const {
		bool hit = aggregate->IntersectP(ray);
		return hit;
	};

	const BBox &Scene::WorldBound() const {
		return bound;
	};


	//DATA
	Primitive *aggregate;
	vector<Light *> lights;
	VolumeRegion *volumeRegion;
	BBox bound;
};

