// Ʈ������ �����͸� ������ �������

// 0~ 16�� ������ �ְ�
// ������ ���ٰ� ����Ѵٴ� �ǹ̰� �ƴϴ�.
// 0�������� ����ϰڴٰ� �ϴ� �ǹ̰� �ȴ�. 
// constantbuffer (�������) : ����� ��ü���� �޶����� ��� �����͸� ��� ���� �������
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

struct Input
{
    // ���ؽ����̴��� �Էµ� ����
	// �ø�ƽ : ��ǲ ����ü�� �������� � �ڷ�� ����� �� �˷��ִ� ��
    float4 Pos : POSITION;
    // UV��ǥ�� : 3���� ������ �����￡ �ؽ��ĸ� ������ ���� ������ �Ǵ� 2���� ��ǥ���Դϴ�. 
    // UV��ǥ�� �ּ� 0 �ִ� 1�� ��ǥ�� ������ 1�� �Ѿ�ų� 0 �̸��� �� ��� �ؽ��İ� �ݺ��Ǿ� ��µȴ�. 
    // �ִ밪�� ��������. ���ϴ� ������ ������ �����ϴٰ���. 
    float4 UV : TEXCOORD;
};

struct Output
{
    // �ȼ����̴��� �Է� �ǰ� ���Ǿ�
    // �����Ͷ������� ������ ������ �ȴ�. 
    // w ������ ���� �� ����Ʈ ���ϰ� �ȼ��� ������ �� ����� ������ ����
    float4 Pos : SV_Position;
    float4 UV : TEXCOORD;
};

// ���ؽ����̴����� ���Ǿ� ��ȯ�Ǵ� ���� Output struct
// �� ����ü�� ����� ���� �ȼ����̴��� �Ѱ��ش�. 
Output Texture_VS(Input _Value)
{
    Output OutputValue = (Output) 0;
	
    _Value.Pos.w = 1.0f;
    // ������������� �� : mul �Լ� ���
    OutputValue.Pos = mul(_Value.Pos, WorldViewProjectionMatrix);
    //OutPutValue.Pos = _Value.Pos;
    OutputValue.UV = _Value.UV;

    return OutputValue;
}
 
cbuffer OutPixelColor : register(b0)
{
    float4 OutColor;
}

// �ؽ��ĸ� ����Ϸ��� 
Texture2D DiffuseTex : register(t0); 

// ���÷�
// �ؽ��ĸ� ��� �ҷ����̰ڳĴ� ����, 
SamplerState CLAMPSAMPLER : register(s0);

// �ȼ����̴������� ���ؽ����̴����� ��ȯ�� ���� �޾Ƽ�
// �ȼ��� ��������. 
float4 Texture_PS(Output _Value) : SV_Target0
{
    // ������ ǥ����
    // float4
    // float4.xy == float2
    // float4.xyz == float3 
    float4 Color = DiffuseTex.Sample(CLAMPSAMPLER, _Value.UV.xy);
  
    Color.r += 0.1f;
    Color.g += 0.1f;
    Color.b += 0.11f;
    Color.a;
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
