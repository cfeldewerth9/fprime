// ======================================================================
// \title  MathReceiver.hpp
// \author cfeldewerth
// \brief  hpp file for MathReceiver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef MathReceiver_HPP
#define MathReceiver_HPP

#include "Ref/MathReceiver/MathReceiverComponentAc.hpp"

namespace Ref {

  class MathReceiver :
    public MathReceiverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object MathReceiver
      //!
      MathReceiver(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object MathReceiver
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object MathReceiver
      //!
      ~MathReceiver();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for mathOpIn
      //!
      void mathOpIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 val1, /*!< 
      The first operand
      */
          const Ref::MathOp &op, /*!< 
      The operation
      */
          F32 val2 /*!< 
      The second operand
      */
      );

      //! Handler implementation for schedIn
      //!
      void schedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< 
      The call order
      */
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for CLEAR_EVENT_THROTTLE command handler
      //! Clear the event throttle
      void CLEAR_EVENT_THROTTLE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

    PRIVATE:

      //! Implementation for parameterUpdated
      //!
      void parameterUpdated(
          const FwPrmIdType id
      );

    };

} // end namespace Ref

#endif
