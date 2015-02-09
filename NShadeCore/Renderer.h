#pragma once
#pragma comment(lib, "D3DCompiler.lib")

#ifndef PS_PROFILE
#define PS_PROFILE {"ps_5_0" }
#endif

#ifndef VS_PROFILE
#define VS_PROFILE {"vs_5_0" }
#endif

#ifndef GS_PROFILE
#define GS_PROFILE { "ps_5_0" }
#endif

#ifndef HS_PROFILE
#define HS_PROFILE { "hs_5_0" }
#endif

#ifndef DS_PROFILE
#define DS_PROFILE { "ds_5_0" }
#endif

#include "includes.h"
#include "d3dcompiler.h"


class Renderer
{
public:
	Renderer(DeviceResources* pResources, bool useSwapChain);
	~Renderer();
public:
	HRESULT	ResizeSwapChain(UINT32 newWidth, UINT32 newHeight);
	HRESULT SetShaderParameters();
	HRESULT	Initialize();
	HRESULT	Render();
public:
	void						ClearScene();
	ID3D11Device*				const GetDevice(){ return DeviceResource()->Device; }
	ID3D11DeviceContext*		const GetDeviceContext(){ return DeviceResource()->DeviceContext; }
	DeviceResources*			const DeviceResource(){ return m_pDeviceResources.get(); }
private:
	/* swap chain */
	HRESULT	CreateSwapChainDesciption();
	HRESULT CreateSwapChain();

	/* constant buffer */
	HRESULT CreateConstantBufferDescription();
	HRESULT CreateConstantBuffer();

	/* depth buffer */
	HRESULT CreateDepthBufferDescription();
	HRESULT CreateDepthBuffer();

	/* depth stencil */
	HRESULT CreateDepthStencilDescription();
	HRESULT CreateDepthStencilViewDescription();
	HRESULT CreateDepthStencil();

	/* rasterizer */
	HRESULT CreateRasterizerDescription();
	HRESULT CreateRasterizer();

	HRESULT CreateViewPort();

	/* sahders */
	HRESULT	SetVertexShader(LPCWSTR compiledShaderFile);
	HRESULT	CompileVertexShader(LPCWSTR shaderSource);

	HRESULT SetHullShader(LPCWSTR compiledShaderFile);
	HRESULT CompileHullShader(LPCWSTR shaderSource);

	HRESULT SetDomainShader(LPCWSTR compiledShaderFile);
	HRESULT CompileDomainShader(LPCWSTR shaderSource);

	HRESULT SetGeometryShader(LPCWSTR compiledShaderFile);
	HRESULT CompileGeometryShader(LPCWSTR shaderSource);

	HRESULT SetPixelShader(LPCWSTR compiledShaderFile);
	HRESULT CompilePixelShader(LPCWSTR shaderSource);

	HRESULT CompileShader(LPCWSTR compiledShaderFile, ID3DBlob *blob, LPCSTR shaderProfile);
private:
	shared_ptr<DeviceResources>			m_pDeviceResources;
	shared_ptr<ShaderSet>				m_pShaderSet;

	ID3D11Texture2D*					m_pBackBuffer;
	ID3D11Texture2D*					m_pDepthStencilBuffer;
	ID3D11DepthStencilState*			m_pDepthStencilState;

	ID3D11RasterizerState*				m_pRasterizerState;

	LPCWSTR								m_standardVertexShader = L"VertexShader.cso";
	LPCWSTR								m_standardPixelShader = L"PixelShader.cso";

	DXGI_SWAP_CHAIN_DESC				m_pSwapChainDescription;
	D3D11_TEXTURE2D_DESC				m_pDepthBufferDesc;
	D3D11_DEPTH_STENCIL_DESC			m_pDepthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC		m_pDepthStencilViewDesc;
	D3D11_RASTERIZER_DESC				m_pRasterizerDesc;

	bool								m_isRendering;
	bool								m_loadingComplete;
	bool								m_tracking;
	bool								m_useSwapChain;
};