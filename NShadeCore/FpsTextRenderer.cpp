#include "stdafx.h"
#include "FpsTextRenderer.h"


FpsTextRenderer::FpsTextRenderer(DeviceResources *resources)
{
	_resources = resources;
}

HRESULT FpsTextRenderer::Initialize()
{
	D2D1_BITMAP_PROPERTIES1 bitmapProperties =
		D2D1::BitmapProperties1(
		D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
		D2D1::PixelFormat(_resources->RenderQuality->TextureFormat, D2D1_ALPHA_MODE_PREMULTIPLIED),
		_resources->Dpi,
		_resources->Dpi);

	IDXGISurface2* dxgiBackBuffer;
	_resources->SwapChain->GetBuffer(0, IID_PPV_ARGS(&dxgiBackBuffer));

	//ID2D1Bitmap1* targetBitmap;
	// DeviceContext()->CreateBitmapFromDxgiSurface(dxgiBackBuffer, &bitmapProperties, &targetBitmap);
	// DeviceContext()->SetTarget(targetBitmap);
	// DeviceContext()->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE);
	return 0;
}