#pragma once

#include "Dimension.h"
#include "Vertex.h"
#include "RenderContext.h"
#include <vector>
#include <d3d11.h>

namespace DDEngine
{

	typedef ID3D11ShaderResourceView ShaderResourceView;
	typedef ID3D11SamplerState SamplerState;

	typedef D3D11_FILTER FilterType;
	typedef D3D11_TEXTURE_ADDRESS_MODE TextureAddressMode;
	typedef D3D11_COMPARISON_FUNC ComparisonFunction;

	namespace DXUtils
	{
		
		HRESULT createDeviceAndSwapChain(
			_Out_	ID3D11Device** device,
			_Out_	ID3D11DeviceContext** context, 
			_Out_	IDXGISwapChain** swapChain, 
			_Out_	ID3D11RenderTargetView** renderTargetView,
			_In_	HWND hwnd,
			_In_	UINT multiSampling
		);

		HRESULT createRasterizerState(
			_In_	ID3D11Device* device,
			_Out_	ID3D11RasterizerState** rasterizerState,
			_In_	D3D11_CULL_MODE cullMode, 
			_In_	D3D11_FILL_MODE fillMode, 
			_In_	INT depthBias
		);
		
		HRESULT createAndCompileVertexShader(
			_In_	ID3D11Device* device,
			_In_	WCHAR* shaderName,
			_In_	LPCSTR entryPoint,
			_In_	LPCSTR shaderModel,
			_Out_	ID3D11VertexShader** vertexShader
		);

		HRESULT createAndCompilePixelShader(
			_In_	ID3D11Device* device,
			_In_	WCHAR* shaderName,
			_In_	LPCSTR entryPoint,
			_In_	LPCSTR shaderModel,
			_Out_	ID3D11PixelShader** pixelShader
		);

		HRESULT createAndCompileGeometryShader(
			_In_	ID3D11Device* device,
			_In_	WCHAR* shaderName,
			_In_	LPCSTR entryPoint,
			_In_	LPCSTR shaderModel,
			_Out_	ID3D11GeometryShader** geometryShader,
			_In_	const D3D11_SO_DECLARATION_ENTRY* layoutDesc,
			_In_	UINT numElements
		);

		HRESULT createVertexShaderFromMemory(
			_In_	ID3D11Device* device,
			_In_	LPVOID dataBlob,
			_In_	DWORD dataSize,
			_In_	LPCSTR entryPoint,
			_In_	LPCSTR shaderModel,
			_Out_	ID3D11VertexShader** vertexShader
		);

		HRESULT createPixelShaderFromMemory(
			_In_	ID3D11Device* device,
			_In_	LPVOID dataBlob,
			_In_	DWORD dataSize,
			_In_	LPCSTR entryPoint,
			_In_	LPCSTR shaderModel,
			_Out_	ID3D11PixelShader** pixelShader
		);

		HRESULT createGeometryShaderFromMemory(
			_In_	ID3D11Device* device,
			_In_	LPVOID dataBlob,
			_In_	DWORD dataSize,
			_In_	LPCSTR entryPoint,
			_In_	LPCSTR shaderModel,
			_Out_	ID3D11GeometryShader** geometryShader,
			_In_	const D3D11_SO_DECLARATION_ENTRY* layoutDesc,
			_In_	UINT numElements
		);

		HRESULT createVertexShaderFromBinary(
			_In_	ID3D11Device* device,
			_In_	WCHAR* shaderName, 
			_Out_	ID3D11VertexShader** vertexShader
		);

		HRESULT createPixelShaderFromBinary(
			_In_	ID3D11Device* device,
			_In_	WCHAR* shaderName, 
			_Out_	ID3D11PixelShader** pixelShader
		);

		HRESULT createGeometryShaderFromBinary(
			_In_	ID3D11Device* device,
			_In_	WCHAR* shaderName,
			_Out_	ID3D11GeometryShader** geometryShader
			);

		HRESULT createIndexBuffer(
			_In_	ID3D11Device* device,
			_In_	std::vector<DWORD>* indices, 
			_Out_	ID3D11Buffer** indexBuffer
		);

		HRESULT createVertexBuffer(
			_In_ ID3D11Device* device, 
			_In_ const void* pSysMem, 
			_In_ UINT structureSize, 
			_Out_ ID3D11Buffer** vertexBuffer
		);

		template <typename T>
		HRESULT createVertexBuffer(
			_In_ ID3D11Device* device,
			_In_ std::vector<T>* vertices,
			_Out_ ID3D11Buffer** vertexBuffer
		) {
			return createVertexBuffer(device, &(*vertices)[0], sizeof(T) * vertices->size(), vertexBuffer);
		}

		HRESULT createDepthStencilBuffer(
			_In_	ID3D11Device* device,
			_In_	ID3D11DeviceContext* context,
			_In_	Dimension screenDimension, 
			_Out_	ID3D11DepthStencilView** depthStencilView, 
			_Out_	ID3D11Texture2D** epthStencilBuffer,
			_In_	UINT multiSampling
		);

		HRESULT createConstatnBuffer(
			_In_	ID3D11Device* device,
			_In_	UINT byteWidth, 
			_Out_	ID3D11Buffer** constantBuffer
		);

		HRESULT createInputLayout(
			_In_	ID3D11Device* device,
			_In_	WCHAR* shaderName, 
			_In_	LPCSTR entryPoint,
			_In_	LPCSTR shaderModel,
			_Out_	ID3D11InputLayout** inputLayout, 
			_In_	const D3D11_INPUT_ELEMENT_DESC* layoutDesc,
			_In_	UINT numElements
		);

		HRESULT createInputLayoutFromMemory(
			_In_	ID3D11Device* device,
			_In_	LPVOID dataBlob,
			_In_	DWORD dataSize,
			_In_	LPCSTR entryPoint,
			_In_	LPCSTR shaderModel,
			_Out_	ID3D11InputLayout** inputLayout,
			_In_	const D3D11_INPUT_ELEMENT_DESC* layoutDesc,
			_In_	UINT numElements
		);

		HRESULT createInputLayoutFromBinary(
			_In_	ID3D11Device* device,
			_In_	WCHAR* shaderName, 
			_Out_	ID3D11InputLayout** inputLayout, 
			_In_	const D3D11_INPUT_ELEMENT_DESC* layoutDesc,
			_In_	UINT numElements
		);

		HRESULT createSamplerState(
			_In_	ID3D11Device* device,
			_Out_	ID3D11SamplerState** samplerState, 
			_In_opt_ D3D11_SAMPLER_DESC* samplerDesc = NULL
		);

		HRESULT createSamplerState(
			_In_	ID3D11Device* device,
			_Out_	ID3D11SamplerState** samplerState,
			_In_	FilterType filter,
			_In_	TextureAddressMode textureMode,
			_In_	ComparisonFunction comparison,
			_In_opt_ UINT maxAnisotropy = 1
		);

		HRESULT createBlendState(
			_In_	ID3D11Device* device,
			_Out_	ID3D11BlendState** blendState, 
			_In_	D3D11_BLEND_DESC* blendDesc = NULL
		);
		
		HRESULT createCubeTextureResource(
			_In_	ID3D11Device* device,
			_In_	LPCWSTR path, 
			_Out_	ID3D11ShaderResourceView** texture
		);

	}

	namespace TextureUtils {
	
		ShaderResourceView* createTexture(
			_In_	const std::string& file,
			_In_	const RenderContext& Ctx
		);

		/*
		ImageInfo getImageInfo(
			_In_	const std::string& file
		);
		*/
	
	}

}

#include <DirectXMath.h>

namespace DirectX
{
	struct VertexPositionNormalTangentTexture
	{
		VertexPositionNormalTangentTexture()
		{ }

		VertexPositionNormalTangentTexture(XMFLOAT3 const& position, XMFLOAT3 const& normal, XMFLOAT4 const& tangent, XMFLOAT2 const& textureCoordinate)
			: position(position),
			normal(normal),
			tangent(tangent),
			textureCoordinate(textureCoordinate)
		{ }

		VertexPositionNormalTangentTexture(FXMVECTOR position, FXMVECTOR normal, FXMVECTOR tangent, CXMVECTOR textureCoordinate)
		{
			XMStoreFloat3(&this->position, position);
			XMStoreFloat3(&this->normal, normal);
			XMStoreFloat4(&this->tangent, tangent);
			XMStoreFloat2(&this->textureCoordinate, textureCoordinate);
		}

		XMFLOAT3 position;
		XMFLOAT3 normal;
		XMFLOAT4 tangent;
		XMFLOAT2 textureCoordinate;
	};
}