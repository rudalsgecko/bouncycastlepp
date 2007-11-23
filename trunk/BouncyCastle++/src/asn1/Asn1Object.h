// 
// File:   Asn1Object.h
// Author: watsug
//
// Created on November 23, 2007, 1:01 PM
//

#ifndef _ASN1OBJECT_H
#define	_ASN1OBJECT_H

using System.IO;

namespace Org {
  namespace BouncyCastle {
    namespace Asn1 {
  
      class Asn1Object : public Asn1Encodable {      
      public:
        /// <summary>Create a base ASN.1 object from a byte array.</summary>
        /// <param name="data">The byte array to parse.</param>
        /// <returns>The base ASN.1 object represented by the byte array.</returns>
        /// <exception cref="IOException">If there is a problem parsing the data.</exception>
        static Asn1Object FromByteArray(byte[] data) {
          return new Asn1InputStream(data).ReadObject();
        }

        /// <summary>Read a base ASN.1 object from a stream.</summary>
        /// <param name="inStr">The stream to parse.</param>
        /// <returns>The base ASN.1 object represented by the byte array.</returns>
        /// <exception cref="IOException">If there is a problem parsing the data.</exception>
        static Asn1Object FromStream(Stream inStr) {
          return new Asn1InputStream(inStr).ReadObject();
        }

        virtual Asn1Object ToAsn1Object() {
          return this;
        }

        virtual void Encode(DerOutputStream derOut) = 0;
        virtual bool Asn1Equals(Asn1Object asn1Object) = 0;
        virtual int Asn1GetHashCode() = 0;

        virtual bool CallAsn1Equals(Asn1Object obj) {
          return Asn1Equals(obj);
        }

        virtual int CallAsn1GetHashCode() {
          return Asn1GetHashCode();
        }
      }

    } //namespace Asn1
  } //namespace BouncyCastle
} //namespace Org

#endif	/* _ASN1OBJECT_H */
