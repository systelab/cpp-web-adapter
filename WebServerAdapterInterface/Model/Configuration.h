#pragma once

#include <memory>
#include <string>


namespace systelab { namespace web_server {

	class CORSConfiguration;
	class SecurityConfiguration;

	class Configuration
	{
	public:
		inline Configuration(const std::string& hostAddress,
					  unsigned int port,
					  unsigned int threadPoolSize);
		inline Configuration(const Configuration&);
		inline virtual ~Configuration();

		inline std::string getHostAddress() const;
		inline unsigned int getPort() const;
		inline unsigned int getThreadPoolSize() const;

		inline const CORSConfiguration& getCORSConfiguration() const;
		inline CORSConfiguration& getCORSConfiguration();

		inline const SecurityConfiguration& getSecurityConfiguration() const;
		inline SecurityConfiguration& getSecurityConfiguration();

		inline Configuration& operator= (const Configuration& other);

	private:
		std::string m_hostAddress;
		unsigned int m_port;
		unsigned int m_threadPoolSize;
		std::unique_ptr<CORSConfiguration> m_corsConfiguration;
		std::unique_ptr<SecurityConfiguration> m_securityConfiguration;
	};

}}

#include "Configuration.inl"
