#include "MainRenderer.hpp"

#include <Fonts/RendererFonts.hpp>
#include <Fonts/RendererFonts2.hpp>
#include <Guis/RendererGuis.hpp>
#include <Renderer/Renderer.hpp>
#include <Scenes/Scenes.hpp>

namespace test
{
MainRenderer::MainRenderer()
{
	std::vector<std::unique_ptr<RenderStage>> renderStages;

	std::vector<Attachment> renderpassAttachments0 = { Attachment(0, "depth", Attachment::Type::Depth),
		Attachment(1, "swapchain", Attachment::Type::Swapchain, false, VK_FORMAT_R8G8B8A8_UNORM, Colour::White) };
	std::vector<SubpassType> renderpassSubpasses0 = { SubpassType(0, { 0, 1 }) };
	renderStages.emplace_back(std::make_unique<RenderStage>(renderpassAttachments0, renderpassSubpasses0));
	Renderer::Get()->SetRenderStages(std::move(renderStages));

	auto &rendererContainer = GetRendererContainer();
	rendererContainer.Clear();

	rendererContainer.Add<RendererGuis>(Pipeline::Stage(0, 0));
	rendererContainer.Add<RendererFonts>(Pipeline::Stage(0, 0));
	rendererContainer.Add<RendererFonts2>(Pipeline::Stage(0, 0));
}

void MainRenderer::Update()
{
}
}
