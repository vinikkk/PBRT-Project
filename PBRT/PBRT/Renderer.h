#pragma once

#include "Scene.h"

class Renderer
{
public:
	Renderer();
	~Renderer();

	virtual void Render(const Scene *scene) = 0;
	virtual Spectrum Li(const Scene *scene, const RayDifferential &ray,
		const Sample *sample, RNG &rng, MemoryArena &arena,
		Intersection *isect = NULL, Spectrum *T = NULL) const = 0;

	virtual Spectrum Transmittance(const Scene *scene,
		const RayDifferential &ray, const Sample *sample,
		RNG &rng, MemoryArena &arena) const = 0;
};

