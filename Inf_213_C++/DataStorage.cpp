#include "DataStorage.h"


void DataStorage::init(Manufacturer manufacturer, Model model, int serialNumber, Type type, double volume,
	int amountPartitions, double volumePartitions, TypePartitionTable typePartitionTable)
{
	if (serialNumber <= 0) throw std::domain_error("====Ошибка инициализации серийного номера====\n\n");
	if (volume <= 0) throw std::domain_error("====Ошибка инициализации объёма====\n\n");
	if (amountPartitions < 0) throw std::domain_error("====Ошибка инициализации количества разделов====\n\n");
	if (volumePartitions < 0) throw std::domain_error("====Ошибка инициализации  объёма разделов====\n\n");
	if ((amountPartitions == 0 && volumePartitions > 0) || (amountPartitions > 0 && volumePartitions == 0)) 
		throw std::domain_error("====Ошибка инициализации объёма разделов и количества разделов====\n\n");
	if (volumePartitions > volume) throw std::domain_error("====Ошибка инициализации объёма разделов превышающий объём====\n\n");
	if(typePartitionTable == TypePartitionTable::UNDEFINED && amountPartitions != 0 && volumePartitions != 0)
		throw std::domain_error("====Ошибка инициализации таблицы====\n\n");
	_manufacturer = manufacturer;
	_model = model;
	_serialNumber = serialNumber;
	_type = type;
	_volume = volume;
	_amountPartitions = amountPartitions;
	_volumePartitions = volumePartitions;
	_typePartitionTable = typePartitionTable;
}

DataStorage::DataStorage(Manufacturer manufacturer, Model model, int serialNumber, Type type, double volume,
	int amountPartitions, double volumePartitions, TypePartitionTable typePartitionTable)
{
	try
	{
		init(manufacturer, model, serialNumber, type, volume,
			amountPartitions, volumePartitions, typePartitionTable);
	}
	catch (const std::exception& error)
	{
		std::cout << error.what();
	}
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

std::string ToString(Manufacturer manufacturer)
{
	switch (manufacturer)
	{
	case Manufacturer::WD: return "WD";
		break;
	case Manufacturer::Seagate: return "Seagate";
		break;
	case Manufacturer::Toshiba: return "Toshiba";
		break;
	case Manufacturer::ADATA: return "ADATA";
		break;
	case Manufacturer::UNDEFINED: return "UNDEFINED";
		break;
	default:
		return "";
		break;
	}
}

std::string ToString(Model model)
{
	switch (model)
	{
	case Model::Andre: return "Andre";
		break;
	case Model::Halen: return "Halen";
		break;
	case Model::Blin: return "Blin";
		break;
	case Model::Zara: return "Zara";
		break;
	case Model::UNDEFINED: return "UNDEFINED";
		break;
	default:
		return "";
		break;
	}
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
	if (ToString(_manufacturer) == "")
	{
		std::cout << "====Не удалось вывести данные! Объект пуст!====" << std::endl;
		return;
	}

	std::cout << "Производитель: " << ToString(_manufacturer) << std::endl;
	std::cout << "Модель: " << ToString(_model) << std::endl;
	std::cout << "Серийный номер: " << _serialNumber << std::endl;
	std::cout << "Тип: " << ToString(_type) << std::endl;
	std::cout << "Объём: " << _volume << " GB" << std::endl;
	std::cout << "Количество разделов: " << _amountPartitions << std::endl;
	std::cout << "Суммарный объём разделов: " << _volumePartitions << " GB" << std::endl;
	std::cout << "Тип таблицы разделов: " << ToString(_typePartitionTable) << std::endl << std::endl;
}

Manufacturer DataStorage::getManufacturer()
{
	return _manufacturer;
}

Model DataStorage::getModel()
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

void DataStorage::setPartitions(int amount, double volume)
{
	if (amount < 0 || volume < 0) return;
	if (volume > _volume) 
	{
		std::cout << "===Нельзя добавить раздел превыщающий объём диска! Изменения не приняты===\n" << std::endl;
		return;
	}

	if ((amount == 0 && volume == 0) || (amount != 0 && volume != 0))
	{
		_amountPartitions = amount;
		_volumePartitions = volume;
	}
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
