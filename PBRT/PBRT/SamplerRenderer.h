#pragma once

#include "Renderer.h"

class SamplerRenderer :
	public Renderer
{
public:
	SamplerRenderer(Sampler *s, Camera *c, SurfaceIntegrator *si, VolumeIntegrator *vi) {
		sampler = s;
		camera = c;
		surfaceIntegrator = si;
		volumeIntegrator = vi;
	};

	~SamplerRenderer();

	void Render(const Scene *scene) {
		surfaceIntegrator->Preprocess(scene, camera, this);
		volumeIntegrator->Preprocess(scene, camera, this);

		Sample *sample = new Sample(sampler, surfaceIntegrator, volumeIntegrator, scene);

		vector<Task *> renderTasks;

	};

private:
	Sampler *sampler;
	Camera *camera;
	SurfaceIntegrator *surfaceIntegrator;
	VolumeIntegrator *volumeIntegrator;
};

