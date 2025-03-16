#pragma once

#include "../vkutils/commands.h"
#include "../vkutils/image.h"

namespace vk
{
	namespace antialiasing_flags_
	{
		enum antialiasing_flags
		{
			ANTIALIAS_DEFAULT_VIEW = (1 << 0),
			ANTIALIAS_LEFT_VIEW    = (1 << 0),
			ANTIALIAS_RIGHT_VIEW   = (1 << 1),
			ANTIALIAS_AND_COMMIT   = (1 << 2)
		};
	}

	using namespace antialiasing_flags_;

	struct antialias
	{
		virtual ~antialias() {}

		virtual vk::viewable_image* scale_output(
			const vk::command_buffer& cmd,          // CB
			vk::viewable_image* src,                // Source input
			VkImage present_surface,                // Present target. May be VK_NULL_HANDLE for some passes
			VkImageLayout present_surface_layout,   // Present surface layout, or VK_IMAGE_LAYOUT_UNDEFINED if no present target is provided
			const VkImageBlit& request,             // Scaling request information
			rsx::flags32_t mode                     // Mode
		) = 0;
	};
}
