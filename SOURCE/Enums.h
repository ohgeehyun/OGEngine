#pragma once

namespace OG_Utils
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End
	};

	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Max = 16
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}