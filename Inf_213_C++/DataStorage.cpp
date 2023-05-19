#include "DataStorage.h"


void DataStorage::init(std::string manufacturer, std::string model, int serialNumber, Type type, double volume,
	int amountPartitions, double volumePartitions, TypePartitionTable typePartitionTable)
{
	if (manufacturer.empty()) throw std::invalid_argument("====������ ������������� �������������====\n\n");
	if (model.empty()) throw std::invalid_argument("====������ ������������� ������====\n\n");
	if (serialNumber <= 0 || serialNumber > 1000000) throw std::domain_error("====������ ������������� ��������� ������====\n\n");
	if (volume <= 0 ||  volume > 100000) throw std::domain_error("====������ ������������� ������====\n\n");
	if (amountPartitions < 0 || amountPartitions > 20) throw std::domain_error("====������ ������������� ���������� ��������====\n\n");
	if (volumePartitions < 0 || volumePartitions > 100000) throw std::domain_error("====������ �������������  ������ ��������====\n\n");
	if ((amountPartitions == 0 && volumePartitions > 0) || (amountPartitions > 0 && volumePartitions == 0)) 
		throw std::domain_error("====������ ������������� ������ �������� � ���������� ��������====\n\n");
	if (volumePartitions > volume) throw std::domain_error("====������ ������������� ������ �������� ����������� �����====\n\n");
	if(typePartitionTable == TypePartitionTable::UNDEFINED && amountPartitions != 0 && volumePartitions != 0)
		throw std::domain_error("====������ ������������� �������====\n\n");
	_manufacturer = manufacturer;
	_model = model;
	_serialNumber = serialNumber;
	_type = type;
	_volume = volume;
	_amountPartitions = amountPartitions;
	_volumePartitions = volumePartitions;
	_typePartitionTable = typePartitionTable;
}

DataStorage::DataStorage(std::string manufacturer, std::string model, int serialNumber, Type type, double volume,
	int amountPartitions, double volumePartitions, TypePartitionTable typePartitionTable)
{
		init(manufacturer, model, serialNumber, type, volume,
			amountPartitions, volumePartitions, typePartitionTable);
}

DataStorage::DataStorage(DataStorage& dataStorage)
{
	if (this == &dataStorage) return;

	_manufacturer = dataStorage._manufacturer;
	_model = dataStorage._model;
	_serialNumber = dataStorage._serialNumber;
	_type = dataStorage._type;
	_volume = dataStorage._volume;
	_amountPartitions = dataStorage._amountPartitions;
	_volumePartitions = dataStorage._volumePartitions;
	_typePartitionTable = dataStorage._typePartitionTable;
}

std::string ToString(Type type)
{
	switch (type)
	{
	case Type::HDD: return "HDD";
		break;
	case Type::SSD: return "SSD";
		break;
	case Type::UNDEFINED: return "UNDEFINED";
		break;
	default:
		return "";
		break;
	}
}

std::string ToString(TypePartitionTable typePartitionTable)
{
	switch (typePartitionTable)
	{
	case TypePartitionTable::GPT: return "GPT";
		break;
	case TypePartitionTable::MBR: return "MBR";
		break;
	case TypePartitionTable::UNDEFINED: return "UNDEFINED";
		break;
	default:
		return "";
		break;
	}
}

void DataStorage::print()
{
	if (_manufacturer == "")
	{
		std::cout << "====�� ������� ������� ������! ������ ����!====" << std::endl;
		return;
	}

	std::cout << "�������������: " << _manufacturer << std::endl;
	std::cout << "������: " << _model << std::endl;
	std::cout << "�������� �����: " << _serialNumber << std::endl;
	std::cout << "���: " << ToString(_type) << std::endl;
	std::cout << "�����: " << _volume << " GB" << std::endl;
	std::cout << "���������� ��������: " << _amountPartitions << std::endl;
	std::cout << "��������� ����� ��������: " << _volumePartitions << " GB" << std::endl;
	std::cout << "��� ������� ��������: " << ToString(_typePartitionTable) << std::endl << std::endl;
}

std::string DataStorage::getManufacturer()
{
	return _manufacturer;
}

std::string DataStorage::getModel()
{
	return _model;
}

int DataStorage::getSerialNumber()
{
	return _serialNumber;
}

Type DataStorage::getType()
{
	return _type;
}

double DataStorage::getVolume()
{
	return _volume;
}

int DataStorage::getAmountPartitions()
{
	return _amountPartitions;
}

double DataStorage::getVolumePartitions()
{
	return _volumePartitions;
}

TypePartitionTable DataStorage::getTypePartitionTable()
{
	return _typePartitionTable;
}

double DataStorage::getRemainingVolume()
{
	return _volume - _volumePartitions;
}

void DataStorage::setPartitions(int amountPartitions, double volumePartitions)
{
	if (_typePartitionTable == TypePartitionTable::UNDEFINED)
	{
		std::cout << "===������� �������� �� �����������===\n" << std::endl;
		return;
	}

	if (amountPartitions < 0 || volumePartitions < 0)
	{
		std::cout << "===������������� �������� ���������� � ������===\n" << std::endl;
		return;
	}

	if ((amountPartitions == 0 && volumePartitions != 0) || (amountPartitions != 0 && volumePartitions == 0))
	{
		std::cout << "===���������� � ��������� ����� �������� ����� ���� ����� 0 ������ ������������===\n" << std::endl;
		return;
	}

	if (volumePartitions > _volume) 
	{
		std::cout << "===������ �������� ������ ����������� ����� �����! ��������� �� �������===\n" << std::endl;
		return;
	}


		_amountPartitions = amountPartitions;
		_volumePartitions = volumePartitions;
}

void DataStorage::createNewTable(TypePartitionTable type)
{
	if (isThereTable())
	{
		_amountPartitions = 0;
		_volumePartitions = 0;
	}
	_typePartitionTable = type;
}

bool DataStorage::isThereTable()
{
	return _typePartitionTable != TypePartitionTable::UNDEFINED;
}
