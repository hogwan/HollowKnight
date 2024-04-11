
cbuffer TransformData : register(b0)
{
    float4 Scale;
    float4 Rotation;
    float4 Quaternion;
    float4 Position;

    float4 LocalScale;
    float4 LocalRotation;
    float4 LocalQuaternion;
    float4 LocalPosition;

    float4 WorldScale;
    float4 WorldRotation;
    float4 WorldQuaternion;
    float4 WorldPosition;

    float4x4 ScaleMatrix;
    float4x4 RotationMatrix;
    float4x4 PositionMatrix;
    float4x4 LocalWorldMatrix;
    float4x4 WorldMatrix;
    float4x4 View;
    float4x4 Projection;
    float4x4 ViewPort;
    float4x4 WorldViewProjectionMatrix;
}

struct VertexInputType
{
    // ���ؽ����̴��� �Էµ� ����
	// �ø�ƽ : ��ǲ ����ü�� �������� � �ڷ�� ����� �� �˷��ִ� ��
    
    //           ������ ������ � ��������
    float4 Pos : POSITION;
    // UV��ǥ�� : 3���� ������ �����￡ �ؽ��ĸ� ������ ���� ������ �Ǵ� 2���� ��ǥ���Դϴ�. 
    // UV��ǥ�� �ּ� 0 �ִ� 1�� ��ǥ�� ������ 1�� �Ѿ�ų� 0 �̸��� �� ��� �ؽ��İ� �ݺ��Ǿ� ��µȴ�. 
    // �ִ밪�� ��������. ���ϴ� ������ ������ �����ϴٰ���. 
    float4 UV : TEXCOORD;
};

struct PixelInputType
{
    // �ȼ����̴��� �Է� �� ����
    // �����Ͷ��������� ������ ���� 
    // w ������ ���� �� ����Ʈ ���ϰ� �ȼ��� ������ �� ����� ������ ������ ���� �ž�
    float4 Pos : SV_Position;
    float4 UV : TEXCOORD;
};

cbuffer AtlasData : register(b1)
{
    // 0.0 0.5
    float2 FramePos;
    // 0.5 0.5 
    float2 FrameScale;
    // float4 AtlasUV;
}


PixelInputType Texture_VS(VertexInputType _Value)
{
    PixelInputType PixelInputValue = (PixelInputType) 0;
	
    _Value.Pos.w = 1.0f;
    // �����Ʈ���� �� : mul �Լ��� ����Ͽ� ����
    PixelInputValue.Pos = mul(_Value.Pos, WorldViewProjectionMatrix);
    //OutPutValue.Pos = _Value.Pos;
    PixelInputValue.UV.x = (_Value.UV.x * FrameScale.x) + FramePos.x;
    PixelInputValue.UV.y = (_Value.UV.y * FrameScale.y) + FramePos.y;
	
	// �����ܰ迡�� ����� ������.
    // _Value.Pos *= �������������;

    return PixelInputValue;
}
 
cbuffer ColorOption : register(b0)
{
    float4 MulColor;
    float4 PlusColor;
}

// �ؽ��ĸ� ����Ϸ��� 
Texture2D TranslucentTex : register(t1);

// ���÷�
SamplerState CLAMPSAMPLER : register(s0);

float4 Texture_PS(PixelInputType _Value) : SV_Target0
{
    // ������ ǥ����
    // float4
    // float4.xy == float2
    // float4.xyz == float3 
    float4 Color = TranslucentTex.Sample(CLAMPSAMPLER, _Value.UV.xy);
    
    Color.a = 0.3f;
    return Color;
}
// clip <-- �ѹ�Ȯ���غ��� 


// 0��° Ÿ�ٿ� ����϶�� �ǹ̰� �ȴ�. 
//float4 Texture_PS(Output _Value) : SV_Target0
//{
//    return OutColor;
//}

// �Ʒ� ������ �����Ͽ� �� �ڵ�ó�� �ۼ��� �����ϴ�. 
//struct OutColor
//{
//    // ��Ƴ��� ��ȭ���� 0��° ��ȭ���� ����ض�.
//    float4 Color : SV_Target0;
//};

//OutColor Texture_PS(Output _Value)
//{
//    OutColor ReturnColor = (OutColor) 0;
//    ReturnColor.Color = _Value.Color;
//    return ReturnColor;
//}
