#include "stdafx.h"
#include "DeviceResources.h"

DeviceResources::DeviceResources(ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	Device = device;
	DeviceContext = deviceContext;
	BufferCount = 2;
	SwapChainFlags = 0;
	DefaultColor = Colors::LightGray;
	Dpi = 96.00;

	// TODO : Get available formats dynamically
	RenderingQuality quality0 = { 0,  1, DXGI_FORMAT_B8G8R8A8_UNORM,		false }; // Should work for everyone
	RenderingQuality quality1 = { 0,  1, DXGI_FORMAT_D24_UNORM_S8_UINT,		false };
	RenderingQuality quality2 = { 0,  2, DXGI_FORMAT_D24_UNORM_S8_UINT,		true  };
	RenderingQuality quality3 = { 32, 8, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB,	true  };
	RenderingQuality quality4 = { 32, 8, DXGI_FORMAT_B8G8R8A8_UNORM,		true  };

	RenderQuality = new RenderingQuality(quality0);
}

DeviceResources::~DeviceResources()
{

}
