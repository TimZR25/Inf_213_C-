#include "DataStorage.h"


void DataStorage::init(std::string manufacturer, std::string model, int serialNumber, Type type, double volume,
	int amountPartitions, double volumePartitions, TypePartitionTable typePartitionTable)
{
	if (manufacturer.empty()) throw std::invalid_argument("====Ошибка инициализации производителя====\n\n");
	if (model.empty()) throw std::invalid_argument("====Ошибка инициализации модели====\n\n");
	if (serialNumber <= 0 || serialNumber > 1000000) throw std::domain_error("====Ошибка инициализации серийного номера====\n\n");
	if (volume <= 0 ||  volume > 100000) throw std::domain_error("====Ошибка инициализации объёма====\n\n");
	if (amountPartitions < 0 || amountPartitions > 20) throw std::domain_error("====Ошибка инициализации количества разделов====\n\n");
	if (volumePartitions < 0 || volumePartitions > 100000) throw std::domain_error("====Ошибка инициализации  объёма разделов====\n\n");
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
		std::cout << "====Не удалось вывести данные! Объект пуст!====" << std::endl;
		return;
	}

	std::cout << "Производитель: " << _manufacturer << std::endl;
	std::cout << "Модель: " << _model << std::endl;
	std::cout << "Серийный номер: " << _serialNumber << std::endl;
	std::cout << "Тип: " << ToString(_type) << std::endl;
	std::cout << "Объём: " << _volume << " GB" << std::endl;
	std::cout << "Количество разделов: " << _amountPartitions << std::endl;
	std::cout << "Суммарный объём разделов: " << _volumePartitions << " GB" << std::endl;
	std::cout << "Тип таблицы разделов: " << ToString(_typePartitionTable) << std::endl << std::endl;
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
		std::cout << "===Таблица разделов не определенна===\n" << std::endl;
		return;
	}

	if (amountPartitions < 0 || volumePartitions < 0)
	{
		std::cout << "===Отрицательные значения количества и объёма===\n" << std::endl;
		return;
	}

	if ((amountPartitions == 0 && volumePartitions != 0) || (amountPartitions != 0 && volumePartitions == 0))
	{
		std::cout << "===Количество и суммарный объём разделов могут быть равны 0 только одновременно===\n" << std::endl;
		return;
	}

	if (volumePartitions > _volume) 
	{
		std::cout << "===Нельзя добавить раздел превыщающий объём диска! Изменения не приняты===\n" << std::endl;
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
