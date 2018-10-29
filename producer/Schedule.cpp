#include <producer/Schedule.h>
#include <algorithm>

namespace producer {

ProducerScheduleType& ProducerScheduleType::operator=(ProducerScheduleType const& pst)
{
    if (&pst == this) return *this;
    for (auto i : pst.m_producers)
        m_producers.push_back(i);
    return *this;
}

bool ProducerScheduleType::isExist(Address const& address)
{
    auto itr = std::find(m_producers.begin(), m_producers.end(), address);
    if (itr != m_producers.end()) return true;
    return false;
}

// ------------------------
Schedule::Schedule()
{

}

Schedule::~Schedule()
{

}

//@not thread safe
std::vector<Producer> const& Schedule::getActiveProducers() const
{
    return m_activeProducers;
}

void Schedule::schedule()
{

}

void Schedule::addActiveProducer(Producer const& producer)
{

}

void Schedule::addActiveProducer(Address const& address)
{

}

void Schedule::removeActiveProducer(Producer const& producer)
{

}

void Schedule::removeActiveProducer(Address const& producer)
{

}

std::vector<Producer> const & Schedule::getProducerList() const
{
    return m_producerList;
}

void Schedule::addProducer(Producer const& producer)
{
    Guard l{x_producerList};
    for (auto itr = m_producerList.begin(); itr != m_producerList.end(); ++itr) {
        if (itr->getAddress() == producer.getAddress()) {
            if (itr->getTimestamp() < producer.getTimestamp()) {
                *itr = producer;
            }
            return;
        }
    }
    m_producerList.push_back(producer);
}

void Schedule::producerSort()
{
    Guard l{x_producerList};
    std::sort(m_producerList.begin(), m_producerList.end(), ProducerCompareGreater());
    m_producerList.erase(std::unique(m_producerList.begin(), m_producerList.end(), ProducerCompareEqual()), m_producerList.end());
}

}
