#include <iostream>

enum class Type
{
	HDD, SSD, UNDEFINED
};

enum class TypePartitionTable
{
	GPT, MBR, UNDEFINED
};

std::string ToString(Type type);
std::string ToString(TypePartitionTable typePartitionTable);

class DataStorage
{
private:
	std::string _manufacturer, _model;
	Type _type;
	TypePartitionTable _typePartitionTable;
	double _volume, _volumePartitions;
	int _serialNumber, _amountPartitions;

	void init(std::string manufacturer,
		std::string model,
		int serialNumber,
		Type type,
		double volume,
		int amountPartitions,
		double volumePartitions,
		TypePartitionTable typePartitionTable);
public:
	DataStorage(std::string manufacturer = "",
		std::string model = "",
		int serialNumber = 0,
		Type type = Type::UNDEFINED,
		double volume = 0,
		int amountPartitions = 0,
		double volumePartitions = 0,
		TypePartitionTable typePartitionTable = TypePartitionTable::UNDEFINED);

	DataStorage(DataStorage& dataStorage);

	void print();

	std::string getManufacturer();
	std::string getModel();
	int getSerialNumber();
	Type getType();
	double getVolume();
	int getAmountPartitions();
	double getVolumePartitions();
	TypePartitionTable getTypePartitionTable();
	double getRemainingVolume();

	void setPartitions(int amount, double volume);

	void createNewTable(TypePartitionTable type);

	bool isThereTable();
};

