#include "doctest.h"
#include <vtil/vtil>

DOCTEST_TEST_CASE("bit_count")
{
	vtil::register_desc phys(vtil::register_physical, X86_REG_EAX, 32, 0);
	vtil::register_desc virt(vtil::register_virtual, X86_REG_EAX, 32, 0);

	CHECK(phys.bit_count == 32);
	CHECK(virt.bit_count == 32);
}

DOCTEST_TEST_CASE("bit_offset")
{
	for (int i = 0; i < 8; ++i)
	{
		vtil::register_desc reg(vtil::register_physical, X86_REG_EAX, 32, i);

		CHECK(reg.bit_offset == i);
	}
}

DOCTEST_TEST_CASE("reg_phys_virt_check")
{
	vtil::register_desc phys(vtil::register_physical, X86_REG_EAX, 32, 0);
	vtil::register_desc virt(vtil::register_virtual, X86_REG_EAX, 32, 0);

	CHECK(phys.is_physical());
	CHECK(virt.is_virtual());

	CHECK_FALSE(phys.is_virtual());
	CHECK_FALSE(virt.is_physical());
}

DOCTEST_TEST_CASE("reg_defs")
{
	// Check for reg map?
	for (int reg_def = X86_REG_INVALID + 1; reg_def < X86_REG_ENDING; ++reg_def)
	{
		vtil::register_desc reg(vtil::register_physical, reg_def, 32, 0);

		CHECK(reg.is_valid());
	}
}