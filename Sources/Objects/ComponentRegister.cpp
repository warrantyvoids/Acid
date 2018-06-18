#include "ComponentRegister.hpp"

#include "Animations/MeshAnimated.hpp"
#include "Lights/Light.hpp"
#include "Materials/MaterialDefault.hpp"
#include "Meshes/MeshRender.hpp"
#include "Particles/ParticleSystem.hpp"
#include "Physics/ColliderSphere.hpp"
#include "Physics/Rigidbody.hpp"
#include "Shadows/ShadowRender.hpp"
#include "Skyboxes/CelestialBody.hpp"
#include "Skyboxes/MaterialSkybox.hpp"

namespace fl
{
	ComponentRegister::ComponentRegister() :
		m_components(std::map<std::string, ComponentCreate>())
	{
		RegisterComponent<CelestialBody>("CelestialBody");
		RegisterComponent<ColliderAabb>("AabbCollider");
		RegisterComponent<ColliderSphere>("SphereCollider");
		RegisterComponent<Light>("Light");
		RegisterComponent<MaterialDefault>("MaterialDefault");
		RegisterComponent<MaterialSkybox>("MaterialSkybox");
		RegisterComponent<Mesh>("Mesh");
		RegisterComponent<MeshAnimated>("MeshAnimated");
		RegisterComponent<MeshRender>("MeshRender");
		RegisterComponent<ParticleSystem>("ParticleSystem");
		RegisterComponent<Rigidbody>("Rigidbody");
		RegisterComponent<ShadowRender>("ShadowRender");
	}

	ComponentRegister::~ComponentRegister()
	{
	}

	ComponentRegister::ComponentCreate ComponentRegister::GetComponentCreate(const std::string &name)
	{
		auto component = m_components.find(name);

		if (component == m_components.end())
		{
			return nullptr;
		}

		return (*component).second;
	}

	void ComponentRegister::DeregisterComponent(const std::string &name)
	{
		auto component = m_components.find(name);

		if (component == m_components.end())
		{
			return;
		}

		m_components.erase(component);
	}

	std::shared_ptr<IComponent> ComponentRegister::CreateComponent(const std::string &name)
	{
		auto found = m_components.find(name);

		if (found == m_components.end())
		{
			fprintf(stderr, "Could not find registered component: '%s'\n", name.c_str());
			return nullptr;
		}

		return ((*found).second)();
	}
}