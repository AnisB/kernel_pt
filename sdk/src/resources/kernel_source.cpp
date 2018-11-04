// Internal includes
#include "resources/kernel_source.h"

// Bento includes
#include <bento_base/stream.h>

namespace bento
{
	const uint32_t KERNEL_SOURCE_VERSION =  1;

	void pack_type(bento::Vector<char>& buffer, const noiseless::TKernelSource& kernelSource)
	{
		bento::pack_bytes(buffer, KERNEL_SOURCE_VERSION);
		bento::pack_vector_bytes(buffer, kernelSource.data);
	}

	bool unpack_type(const char*& stream, noiseless::TKernelSource& kernelSource)
	{
		// Read the version
		uint32_t data_stream_version;
		bento::unpack_bytes(stream, data_stream_version);

		// Stop if this does not match the current version
		if (data_stream_version != bento::KERNEL_SOURCE_VERSION) return false;
		bento::unpack_vector_bytes(stream, kernelSource.data);
		return true;
	}
}