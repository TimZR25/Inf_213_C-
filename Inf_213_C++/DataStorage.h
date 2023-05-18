#include <iostream>
#include <vector>

enum class Manufacturer
{
	WD, Seagate, Toshiba, ADATA, UNDEFINED
};

enum class Model
{
	Andre, Halen, Blin, Zara, UNDEFINED
};

enum class Type
{
	HDD, SSD, UNDEFINED
};

enum class TypePartitionTable
{
	GPT, MBR, UNDEFINED
};

std::string ToString(Manufacturer manufacturer);
std::string ToString(Model model);
std::string ToString(Type type);
std::string ToString(TypePartitionTable typePartitionTable);

typedef struct PartitionTable
{
	std::vector<double> volume;
	int amount;
	TypePartitionTable type;
	PartitionTable(TypePartitionTable type = TypePartitionTable::UNDEFINED)
	{
		this->amount = 0;
		this->type = type;
	}
}PartitionTable;

class DataStorage
{
private:
	Manufacturer _manufacturer;
	Model _model;
	Type _type;
	TypePartitionTable _typePartitionTable;
	double _volume, _volumePartitions;
	int _serialNumber, _amountPartitions;

	PartitionTable _partitionTable;

	void init(Manufacturer manufacturer,
		Model model,
		int serialNumber,
		Type type,
		double volume,
		int amountPartitions,
		double volumePartitions,
		TypePartitionTable typePartitionTable);
public:
	DataStorage(Manufacturer manufacturer = Manufacturer::UNDEFINED,
		Model model = Model::UNDEFINED,
		int serialNumber = 0,
		Type type = Type::UNDEFINED,
		double volume = 0,
		int amountPartitions = 0,
		double volumePartitions = 0,
		TypePartitionTable typePartitionTable = TypePartitionTable::UNDEFINED);

	DataStorage(DataStorage& dataStorage);

	void print();

	Manufacturer getManufacturer();
	Model getModel();
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

