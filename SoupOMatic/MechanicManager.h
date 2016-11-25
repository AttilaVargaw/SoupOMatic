#pragma once
class MechanicManager
{
public:
	MechanicManager();
	~MechanicManager();

	bool ServeFromSlot(int slotNumber, int creamNumber);

	bool CanPay() {
		return true;
	}
};